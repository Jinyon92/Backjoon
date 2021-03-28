package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Backjoon1043 {
    static int[] parent;
    static int[] level;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int answer = 0;
        parent = new int[n+1];
        level = new int[n+1];
        int party[][] = new int[m][n];

        for(int i=1; i<=n; i++){
            parent[i] = i;
            level[i] = 1;
        }

        st = new StringTokenizer(br.readLine(), " ");
        int size = Integer.parseInt(st.nextToken());
        ArrayList<Integer> truth = new ArrayList<Integer>();
        for(int i=0; i<size; i++){
            truth.add(Integer.parseInt(st.nextToken()));
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine(), " ");
            int partyNum = Integer.parseInt(st.nextToken());
            int key = Integer.parseInt(st.nextToken());
            party[i][0] = key;
            for(int j=1; j<partyNum; j++){
                int person = Integer.parseInt(st.nextToken());
                merge(key, person);
                party[i][j] = person;
            }
        }

        HashSet<Integer> hs = new HashSet<Integer>();
        for(Integer i : truth){
            int val = find(i);
            hs.add(val);
        }

        for(int i=0; i<m; i++){
            boolean flag = false;
            for(int j=0; j<n; j++){
                if(party[i][j] == 0) break;
                int val = find(party[i][j]);

                Iterator iter = hs.iterator();
                while(iter.hasNext()) {
                    if(val == (int)iter.next()){
                        flag = true;
                    }
                }
                if(flag) break;
            }
            if(!flag) answer++;
        }

        System.out.println(answer);
    }

    public static int find(int u){
        if(u == parent[u]) return u;
        else return parent[u] = find(parent[u]);
    }

    public static void merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(level[u] < level[v]){
            int temp = u;
            u = v;
            v = temp;
        }
        parent[v] = u;

        if(level[u] == level[v]) level[u]++;
    }
}
