package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Backjoon2504 {
    static Stack<String> stack;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = br.readLine().split("");
        stack = new Stack<>();
        int len = arr.length;
        int check = 0;

        for(int i=0; i<len; i++){
            if(arr[i].equals("(") || arr[i].equals("[")){
                stack.push(arr[i]);
            }

            if(check == -1 || stack.isEmpty()) {
                System.out.println(0);
                return;
            }

            if(arr[i].equals(")")){
                if(stack.peek().equals("(")){
                    stack.pop();
                    stack.push("2");
                }else{
                    check = stackInnerLoop("(", "[", 2);
                }
            }
            else if(arr[i].equals("]")){
                if(stack.peek().equals("[")){
                    stack.pop();
                    stack.push("3");
                }else{
                    check = stackInnerLoop("[","(", 3);
                }
            }
        }

        check = 0;
        while(!stack.isEmpty()){
            String temp = stack.pop();
            if(temp.equals("(") || temp.equals(")") || temp.equals("[") || temp.equals("]")){
                System.out.println(0);
                return;
            }
            check += Integer.parseInt(temp);
        }

        System.out.println(check);
    }

    private static int stackInnerLoop(String s1, String s2, int val) {
        int result = 0;

        while(!stack.isEmpty()){
            String top = stack.peek();

            if(top.equals(s2)) return -1;
            else if(top.equals(s1)){
                stack.pop();
                result *= val;
                stack.push(String.valueOf(result));
                break;
            }
            else {
                result += Integer.parseInt(stack.pop());
            }
        }

        return result;
    }
}
