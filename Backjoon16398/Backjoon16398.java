package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Backjoon16398 {
    static int graph[][];
    static boolean visited[];
    static ArrayList<Node>[] nodeList;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());

        graph = new int[N+1][N+1];
        nodeList = new ArrayList[N+1];
        visited = new boolean[N+1];
        for(int i=0; i<=N; i++){
            nodeList[i] = new ArrayList<>();
        }

        for(int y=1; y<=N; y++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int x=1; x<=N; x++){
                graph[y][x] = Integer.parseInt(st.nextToken());

                if(y != x){
                    nodeList[y].add(new Node(y,x,graph[y][x]));
                }
            }
        }

        long answer = mst();
        System.out.println(answer);
    }

    private static long mst() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        ArrayList<Node> tempList;
        Node tempNode;
        Queue<Integer> queue = new LinkedList<>();
        long answer = 0;

        queue.add(1);
        while (!queue.isEmpty()){
            int currentNode = queue.poll();
            visited[currentNode] = true;
            tempList = nodeList[currentNode];

            for(int i=0; i<tempList.size(); i++){
                pq.add(tempList.get(i));
            }

            while(!pq.isEmpty()){
                tempNode = pq.poll();

                if(!visited[tempNode.end]){
                    visited[tempNode.end] = true;
                    answer += tempNode.cost;
                    queue.add(tempNode.end);
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
