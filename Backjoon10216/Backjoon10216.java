package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Backjoon10216 {
    static int[] parent;
    static int[] level;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc<=T; tc++){
            int n = Integer.parseInt(br.readLine());
            parent = new int[n+1];
            level = new int[n+1];

            for(int i=1; i<=n; i++){
                parent[i] = i;
                level[i] = 1;
            }

            StringTokenizer st;
            Point[] points = new Point[n+1];
            for(int i=1; i<=n; i++){
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int dist = Integer.parseInt(st.nextToken());

                points[i] = new Point(x,y,dist);
            }

            for(int i=1; i<=n; i++){
                for(int j=i+1; j<=n; j++){
                    int disX = (points[i].x - points[j].x) * (points[i].x - points[j].x);
                    int disY = (points[i].y - points[j].y) * (points[i].y - points[j].y);
                    int dis = (points[i].dist + points[j].dist) * (points[i].dist + points[j].dist);

                    if(disX + disY <= dis){
                        merge(i, j);
                    }
                }
            }

            HashSet<Integer> hs = new HashSet<Integer>();
            for(int i=1; i<=n; i++){
                hs.add(find(i));
            }

            System.out.println(hs.size());
        }1
    }

    static class Point {
        int x;
        int y;
        int dist;

        public Point(int x, int y, int dist){
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    public static int find(int u){
        if(parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }

    public static void merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(level[u] > level[v]){
            int temp = u;
            u = v;
            v = temp;
        }

        parent[u] = v;
        if(level[u] == level[v]) level[v]++;
    }

}
