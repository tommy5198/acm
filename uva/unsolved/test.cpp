#include <cstdio>

using namespace std;

typedef struct
{
int group, size, enemy;
}PERSON;

PERSON people[10001];

int findSet(int a)
{
    if(a == -1)
		return -1;
	if(people[a].group == a)
		return a;

	return people[a].group = findSet(people[a].group);
}

void Union(int x, int y)
{
    if(x != y)
    {
        if(people[x].size < people[y].size)
        {
            people[x].group = people[y].group;
            people[y].size += people[x].size;
        }
        else
        {
            people[y].group = people[x].group;
            people[x].size += people[y].size;
        }
    }
}

int Relationship(int x, int y)
{
    if(x == y)
        return 1;
    else
        return 0;
}

int main()
{
	int i, c, n, x, y;

	scanf("%d", &n);

        for(i=0; i<n; ++i)
        {
            people[i].group = i;
            people[i].size = 1;
            people[i].enemy = -1;
        }
        if(people[-1].enemy == -1) puts("1");
        while(scanf("%d%d%d", &c, &x, &y) && c)
        {
            x = findSet(x);
            y = findSet(y);
            int x_enemy = people[x].enemy = findSet(people[x].enemy);
            int y_enemy = people[y].enemy = findSet(people[y].enemy);

            switch(c)
            {
                case 1:
                    if(x_enemy == y || y_enemy == x)
                        printf("-1\n");
                    else
                    {
                        Union(x, y);
                        if(y_enemy != -1) people[x].enemy = y_enemy;
                        if(x_enemy != -1) people[y].enemy = x_enemy;
                    }
                    break;

                case 2:
                    if(x == y)
                        printf("-1\n");
                    else
                    {
                        people[x].enemy = y;
                        people[y].enemy = x;
                        Union(x, y_enemy);
                        Union(y, x_enemy);
                    }
                    break;

                case 3:
                    printf("%d\n", Relationship(x, y));
                    break;

                case 4:
                    printf("%d\n", Relationship(x, y_enemy) || Relationship(y, x_enemy));
                    break;
            }
        }
    return 0;
}

