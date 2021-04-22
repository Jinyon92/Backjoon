package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Backjoon6497 {
    static ArrayList<Node>[] nodeList;
    static boolean visited[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        while(true) {
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            if(N==0 && M==0) break;

            nodeList = new ArrayList[N];
            visited = new boolean[N];
            for (int i = 0; i < N; i++) {
                nodeList[i] = new ArrayList<>();
            }

            int total = 0;
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine(), " ");

                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());

                nodeList[x].add(new Node(x, y, z));
                nodeList[y].add(new Node(y, x, z));
                total += z;
            }

            int answer = total - mst();
            System.out.println(answer);
        }
    }

    private static int mst() {
        int answer = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);

        while(!queue.isEmpty()){
            int cur = queue.poll();
            visited[cur] = true;

            for(int i=0; i<nodeList[cur].size(); i++){
                pq.add(nodeList[cur].get(i));
            }

            while(!pq.isEmpty()){
                Node curNode = pq.poll();

                if(!visited[curNode.end]){
                    queue.add(curNode.end);
                    answer += curNode.cost;

                    break;
                }
            }
        }

        return answer;
    }

    static class Node implements Comparable<Node>{
        int start;
        int end;
        int cost;

        public Node(int start, int end, int cost){
            this.start = start;
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
}
