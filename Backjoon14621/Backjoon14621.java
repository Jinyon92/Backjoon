package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Backjoon14621 {

    static int parent[];
    static int level[];
    static ArrayList<Node> nodeList;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[] university = new char[N+1];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=1; i<=N; i++){
            university[i] = st.nextToken().charAt(0);
        }

        nodeList = new ArrayList<>();
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine(), " ");

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            nodeList.add(new Node(start,end,cost));
        }

        Collections.sort(nodeList, (e1,e2) -> e1.cost - e2.cost);

        parent = new int[N+1];
        level = new int[N+1];
        for(int i=1; i<=N; i++){
            parent[i] = i;
            level[i] = 1;
        }

        int ans = 0, cnt = 0;
        for(int i=0; i<nodeList.size(); i++){
            Node node = nodeList.get(i);

            if(find(node.start) != find(node.end)){
                if(university[node.start] != university[node.end]){
                    cnt++;
                    ans += node.cost;
                    merge(node.start, node.end);
                }
            }
        }

        if(cnt != N-1) ans = -1;
        System.out.println(ans);

    }

    private static int find(int u) {
        if(parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }

    private static void merge(int v, int u){
        v = find(v);
        u = find(u);

        if(v == u) return;

        if(level[u] < level[v]){
            int temp = u;
            u = v;
            v = temp;
        }

        parent[v] = u;
        if(level[u] == level[v]) {
            level[u]++;
        }
    }

    static public class Node{
        int start;
        int end;
        int cost;

        public Node(int start, int end, int cost){
            this.start = start;
            this.end = end;
            this.cost = cost;
        }
    }
}
