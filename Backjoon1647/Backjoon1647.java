package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Backjoon1647 {
    static ArrayList<Node>[] nodeList;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        nodeList = new ArrayList[N+1];
        visited = new boolean[N+1];

        for(int i=0; i<=N; i++){
            nodeList[i] = new ArrayList<>();
        }
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            nodeList[u].add(new Node(u,v,cost));
            nodeList[v].add(new Node(v,u,cost));
        }

        int answer = mst();
        System.out.println(answer);
    }

    private static int mst() {
        int answer = 0;
        int lastVal = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Node> tempList;
        Node tempNode;

        q.offer(1);
        while(!q.isEmpty()){
            int curNode = q.poll();
            visited[curNode] = true;
            tempList = nodeList[curNode];
            for(int i=0; i<tempList.size(); i++){
                if(!visited[tempList.get(i).end]){
                    pq.add(tempList.get(i));
                }
            }

            while (!pq.isEmpty()){
                tempNode = pq.poll();

                if(!visited[tempNode.end]){
                    visited[tempNode.end] = true;
                    answer += tempNode.cost;
                    lastVal = Math.max(lastVal, tempNode.cost);
                    q.offer(tempNode.end);
                    break;
                }
            }
        }

        return answer-lastVal;
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
