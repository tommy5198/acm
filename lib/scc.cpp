void dfs_fin(int U) {
    for(Each V in edge(U,V))
        if(!vis[V])
            dfs_fin(V);
    fin_stk.push(U);
}

void dfs_scc(int U) {
    sccV[scc_cnt] = U;
    for(Each V in edge(V, U)) //reverse edge
        if(!vis[V])
            dfs_scc(V);
}

void scc() {
    for(Each V in G) 
        if(!vis[V]) dfs_fin(V);
    for(V = stk.top, stk.pop)// foreach V in decre fin time
        if(!vis[V]) dfs_scc(V), scc_cnt++;
    for(Each (U,V) in G) {
        if(sccV[U] != sccV[V])
            // (sccV[U], sccv[V]) = true;
    }
}
