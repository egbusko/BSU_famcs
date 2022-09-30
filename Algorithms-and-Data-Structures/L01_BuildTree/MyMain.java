import java.io.*;
import java.util.*;


public class MyMain implements Runnable {


    public static class Tree {
        public class Node {
            public int key;
            public Node left;
            public Node right;

            public Node(int key) {
                this.key = key;
            }
        }

        List<Integer> mylist = new ArrayList<>();
        private Node root;

        public void makeTree() throws FileNotFoundException {
            File fileIn = new File("output2.txt");
            Scanner sc = new Scanner(fileIn);
            while (sc.hasNext()) {
                insert(sc.nextInt());
            }
        }

/*        private void insert(int x) {
            root = doInsert(root, x);
        }

        private Node doInsert(Node node, int x) {
            Node tmpNode = node;
            if (node == null) {
                return new Node(x);
            }
            if (x%100==0){
                System.out.println(x);
            }


            while (true) {
                if ((x < tmpNode.key)) {
                    if (tmpNode.left != null) {
                        tmpNode = tmpNode.left;
                        continue;
                    }else {
                        tmpNode.left = new Node(x);
                        break;
                    }
                }

                if ((x > tmpNode.key)) {
                    if (tmpNode.right != null) {
                        tmpNode = tmpNode.right;
                        continue;
                    }else {
                        tmpNode.right = new Node(x);
                        break;
                    }
                }
            }

            if (x < node.key) {
                node.left = doInsert(node.left, x);
            } else if (x > node.key) {
                node.right = doInsert(node.right, x);
            }
            return node;
        }*/



        private void insert(int x) {
            root = doInsert(root, x);
        }

        private Node doInsert(Node node, int x) {
            if (node == null) {
                return new Node(x);
            }
            if (x < node.key) {
                node.left = doInsert(node.left, x);
            } else if (x > node.key) {
                node.right = doInsert(node.right, x);
            }
            return node;
        }

        public void runTree() throws IOException {
            if (root != null) {
                runNode(root);
            }
        }

        private void runNode(Node node) {
            mylist.add(node.key);
            if (node.left != null) {
                runNode(node.left);
            }
            if (node.right != null) {
                runNode(node.right);
            }
        }


        /*public void countTree() {
            contPreOrder(root);
        }

        private void contPreOrder(Node top) {
            Stack<Node> stack = new Stack<>();
            while (top != null || !stack.empty()) {
                if (!stack.empty()) {
                    top = stack.pop();
                }
                while (top != null) {
                    mylist.add(top.key);
                    if (top.right != null) stack.push(top.right);
                    top = top.left;
                }
            }
        }*/


        public void writeNums() throws IOException {
            try (PrintWriter pw = new PrintWriter("output.txt")) {
                for (int i : mylist) {
                    pw.println(i);
                }
            }
        }

        public void writeNums10() throws IOException {
            try (PrintWriter pw = new PrintWriter("output2.txt")) {
                int i = 0;
                while (i <= 1000000) {
                    pw.println(i++);
                }
            }
        }
    }


    public static void main(String[] args) {
        new Thread(null, new MyMain(), "", 64 * 1024 * 1024).start();
        /*try {
            Tree obj = new Tree();
            obj.makeTree();
            obj.countTree();
            obj.writeNums();
            //obj.writeNums10();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }*/
    }

    @Override
    public void run() {
        try {
            Tree obj = new Tree();
            obj.makeTree();
            obj.runTree();
            obj.writeNums();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}