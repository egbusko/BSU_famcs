import java.io.*;

public class MyMain {
    static class Node {
        public int min;
        public int max;
        public int left;
        public int right;
        public int value;
        public int parent;

        Node() {
            min = Integer.MAX_VALUE;
            max = Integer.MIN_VALUE;
            left = 0;
            right = 0;
            value = 0;
            parent = 0;
        }
    }

    static int n;
    static int arrSize;
    static Node[] tree;
    static int[] isDone;

    public static void main(String[] args) throws FileNotFoundException {
        try (BufferedReader reader = new BufferedReader(new FileReader("bst.in"))) {
            n = Integer.parseInt(reader.readLine());
            arrSize = 8 * (int) Math.pow(10, 5) + 1;
            isDone = new int[arrSize];
            tree = new Node[arrSize];
            isDone[0] = 1;

            for (int i = 0; i < arrSize; i++) {
                tree[i] = new Node();
            }
            tree[1].parent = 0;
            tree[1].value = Integer.parseInt(reader.readLine());

            String[] buf;
            int value;
            int parent;

            for (int i = 2; i <= n; i++) {
                buf = reader.readLine().split(" ");
                value = Integer.parseInt(buf[0]);
                parent = Integer.parseInt(buf[1]);

                if (buf[2].equals("L")) {
                    tree[parent].left = i;
                } else {
                    tree[parent].right = i;
                }
                tree[i].value = value;
                tree[i].parent = parent;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        PrintWriter pw = new PrintWriter("bst.out");
        if (check()) {
            pw.print("YES");
        } else {
            pw.print("NO");
        }
        pw.close();
    }


    static boolean check() {
        int cur_left;
        int cur_right;
        int current = n;
        boolean flag = true;

        while (current != 0 && flag) {
            if (isDone[tree[current].left] == 0) {
                current = tree[current].left;
            } else {
                if (isDone[tree[current].right] == 0) {
                    current = tree[current].right;
                } else {
                    cur_left = tree[current].left;
                    cur_right = tree[current].right;
                    flag = (cur_left == 0 || tree[cur_left].max < tree[current].value) && (cur_right == 0 || tree[current].value <= tree[cur_right].min);
                    if (!flag) {
                        break;
                    }
                    if (cur_left == 0) {
                        tree[current].min = tree[current].value;
                    } else {
                        tree[current].min = tree[cur_left].min;
                    }
                    if (cur_right == 0) {
                        tree[current].max = tree[current].value;
                    } else {
                        tree[current].max = tree[cur_right].max;
                    }
                    isDone[current] = 1;
                    current = tree[current].parent;
                }
            }
        }
        return flag;
    }
}

/*
public class MyMain {
    public static void main(String[] args) {
        try {
            Tree obj = new Tree();
            obj.enterInform();
            obj.outRes();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}*/

