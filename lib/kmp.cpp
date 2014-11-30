char P[Plen];   // pattern string
char T[Tlen];   // target string
int pi[Plen];   // pi[i]: max len prefix == suffix in P[0..i]

void kmp_pre() {
    pi[0] = 0;
    for(int i = 1; i < Plen; i++) {
        pi[i] = pi[i - 1];
        while(pi[i] > 0 && P[i] != P[pi[i]])
            pi[i] = pi[pi[i] - 1];
        if(P[i] == P[pi[i]])
            pi[i]++;
    }
}

void kmp() {
    for(int i = 0, j = 0; i < Tlen; i++) {
        while(j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if(T[i] == P[j]) j++;
        if(j == Plen) ; // match (i - Plen + 1)
    }
}

