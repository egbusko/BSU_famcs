import java.io.*;
import java.util.Scanner;


class Tree {
    public class Node {
        public int key;
        public Node left;
        public Node right;

        public int height = 0;
        public long msl = 0;
        public int num_leaves = 0;
        public long b = 1;
        public long a = 0;

        public Node(int key) {
            this.key = key;
        }
    }

    public Node root;
    public long maxSemipathLength = 0;
    //List<Integer> mylist = new ArrayList<>();
    public int intToDelete = Integer.MAX_VALUE;

    public void makeTree() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("tst.in"));
        String t;

        while ((t = reader.readLine()) != null) {
            insert(Integer.parseInt(t));
        }
    }


    public void insert(int num) {
        if (root == null) {
            root = new Node(num);
            return;
        }

        Node node = root;
        while (true) {
            if (num < node.key) {
                if (node.left == null) {
                    node.left = new Node(num);
                    return;
                } else {
                    node = node.left;
                }
            } else if (num > node.key) {
                if (node.right == null) {
                    node.right = new Node(num);
                    return;
                } else {
                    node = node.right;
                }
            } else {
                return;
            }
        }
    }

        /*private void insert(int x) {
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
        }*/



    //обратный левый  TODO!! ?
    public void countHeightsBL(){
        if (root != null) {
            root.height = runBackLeft(root);
        }
    }

    private int runBackLeft(Node node) {
        int h_left = -1;
        int h_right = -1;
        if (node.left != null) {
            h_left = runBackLeft(node.left);
        }
        if (node.right != null) {
            h_right = runBackLeft(node.right);
        }

        if ((h_right < 0) && (h_left < 0)) {
            node.height = 0;
            node.msl = 0;
            node.num_leaves = 1;
        } else if ((h_right >= 0) && (h_left < 0)) {
            node.height = h_right + 1;
            node.msl = node.right.height + 1;
            node.num_leaves = node.right.num_leaves;
        } else if ((h_right < 0) && (h_left >= 0)) {
            node.height = h_left + 1;
            node.msl = node.left.height + 1;
            node.num_leaves = node.left.num_leaves;
        } else if ((h_right >= 0) && (h_left >= 0)) {
            if (h_right > h_left) {
                node.height = h_right + 1;
                node.msl = node.right.height + node.left.height + 2;
                node.num_leaves = node.right.num_leaves;
            }
            if (h_right < h_left) {
                node.height = h_left + 1;
                node.msl = node.right.height + node.left.height + 2;
                node.num_leaves = node.left.num_leaves;
            }
            if (h_right == h_left) {
                node.height = h_right + 1;
                node.msl = node.right.height + node.left.height + 2;
                node.num_leaves = node.right.num_leaves + node.left.num_leaves;
            }
        }
        if (node.msl > maxSemipathLength) {
            maxSemipathLength = node.msl;
        }
        return node.height;
    }


    public void setA_B(Node node) {
        if (node == null) return;

        if (node.msl == maxSemipathLength) {
            if (node.left != null) node.b *= node.left.num_leaves;
            if (node.right != null) node.b *= node.right.num_leaves;
        } else {
            node.b = 0;
        }

        if (node == root) node.a = 0;
        if (node.left == null && node.right != null) {
            node.right.a = node.b + node.a;
        }
        if (node.right == null && node.left != null) {
            node.left.a = node.b + node.a;
        }
        if (node.left != null && node.right != null) {
            if (node.left.height > node.right.height) {
                node.left.a = node.a + node.b;
                node.right.a = node.b;
            } else if (node.left.height < node.right.height) {
                node.left.a = node.b;
                node.right.a = node.b + node.a;
            } else {
                node.left.a = node.b + (node.left.num_leaves * node.a / node.num_leaves);
                node.right.a = node.b + (node.right.num_leaves * node.a / node.num_leaves);
            }
        }
        setA_B(node.left);
        setA_B(node.right);
    }


    public void getDelNum(Node node) {
        if (node == null) return;
        if ((node.a + node.b) % 2 == 0 && (node.a + node.b != 0) && node.key < intToDelete) {
            intToDelete = node.key;
        }
        getDelNum(node.left);
        getDelNum(node.right);
    }

    public Node deleteNum(Node current, long value) {
        if (current == null) {
            return null;
        }

        if (value == current.key) {
            if (current == root) {
                if (current.right == null && current.left != null) {
                    root = current.left;
                    return current;
                } else if (current.right != null && current.left == null) {
                    root = current.right;
                    return current;
                }
            }

            if (current.right == null && current.left == null) {
                return null;
            } else if (current.left == null) {
                return current.right;
            } else if (current.right == null) {
                return current.left;
            } else {
                int min = findMin(current.right).key;
                current.key = min;
                current.right = deleteNum(current.right, min);
                return current;
            }
        }
        if (value < current.key) {
            current.left = deleteNum(current.left, value);
            return current;
        }
        current.right = deleteNum(current.right, value);
        return current;
    }

    private Node findMin(Node current) {
        if (current.left != null) {
            return findMin(current.left);
        } else {
            return current;
        }
    }


    //прямой левый
    public void runTreeSL(FileWriter fr) throws IOException {
        if (root != null) {
            runStraightLeft(root, fr);
        }
    }

    public void runStraightLeft(Node node, FileWriter fr) throws IOException {
        //mylist.add(node.key);
        if (node != null) {
            fr.write(node.key + "\n");
            /*System.out.println(node.key + " h==" + node.height
                    + " msl==" + node.msl + " n_leaves==" + node.num_leaves
                    + " a==" + node.a + " b==" + node.b);*/
            if (node.left != null) {
                runStraightLeft(node.left, fr);
            }
            if (node.right != null) {
                runStraightLeft(node.right, fr);
            }
        }
    }
}

public class MyMain implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new MyMain(), "", 128 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            Tree obj = new Tree();
            obj.makeTree();
            obj.countHeightsBL();
            obj.setA_B(obj.root);
            obj.getDelNum(obj.root);

            if (obj.intToDelete != Integer.MAX_VALUE)
                obj.deleteNum(obj.root, obj.intToDelete);

            FileWriter fr = new FileWriter("tst.out");
            obj.runTreeSL(fr);
            fr.close();

        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }
}