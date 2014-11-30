void second_MST_VE(){
    for(Each (u, v) in G not in MST)
        secMST = min(secMST, dfs(u, v)); // remove max edge in u -> v
}

void second_MST_VElgE(){
    for(Each E in MST){
        remove E;
        secMST = min(secMST, MST(G));
        recover E;
    }
}
