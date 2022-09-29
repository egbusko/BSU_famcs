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
        private int intToDelete;
        private Node root;

        public void makeTree() throws FileNotFoundException {
            File fileIn = new File("input.txt");
            Scanner sc = new Scanner(fileIn);
            intToDelete = sc.nextInt();

            while (sc.hasNext()) {
                insert(sc.nextInt());
            }
        }

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



       /* public void deleteNum() {
            Node tmpNode = root;
            while (tmpNode.key != intToDelete) {
                if (intToDelete < tmpNode.key) {
                    tmpNode = tmpNode.left;
                } else
                    tmpNode = tmpNode.right;
            }

            System.out.println(intToDelete + "!!!!!" + tmpNode.key);
        }*/

        /*private void replaceChild(Node _parent, Node _old, Node _new) {
            if (_parent != null) {
                root = _new;
            } else if (_parent.left == _old) {
                _parent.left = _new;
            } else if (_parent.right == _old) {
                _parent.right = _new;
            }
        }

        public void deleteIterativly() {
            Node _parent = null;
            Node v = root;

            while (true) {
                if (v == null)
                    return;
                if (intToDelete < v.key) {
                    _parent = v;
                    v = v.left;
                } else if (intToDelete > v.key) {
                    _parent = v;
                    v = v.right;
                } else
                    break;
            }

            Node result = null;
            Node min_node_parent;
            Node min_node;

            if (v.left != null) {
                result = v.right;
                replaceChild(_parent, v, result);
            } else if (v.right != null) {
                result = v.left;
                replaceChild(_parent, v, result);
            } else {
                min_node_parent = v;
                min_node = v.right;
                while (min_node.left != null) {
                    min_node_parent = min_node;
                    min_node = min_node.left;
                }
                result = v;
                v.key = min_node.key;
                replaceChild(min_node_parent, min_node, min_node.right);
            }
        }*/

        void delete() {
            root = deleteRecursively(root, intToDelete);
        }

        public Node deleteRecursively(Node v, int x) {
            if (v == null) return v;
            if (x < v.key) {
                v.left = deleteRecursively(v.left, x);
                return v;
            } else if (x > v.key) {
                v.right = deleteRecursively(v.right, x);
                return v;
            }

            if (v.left == null) {
                return v.right;
            } else if (v.right == null) {
                return v.left;
            } else {
                int min_key = findMin(v.right).key;
                v.key = min_key;
                v.right = deleteRecursively(v.right, min_key);
                return v;
            }
        }

        public Node findMin(Node v) {
            if (!(v.left == null)) {
                return findMin(v.left);
            } else return v;
        }



        //прямой левый
        public void runTreeSL() throws IOException {
            if (root != null) {
                runStraightLeft(root);
            }
        }

        private void runStraightLeft(Node node) {
            mylist.add(node.key);
            if (node.left != null) {
                runStraightLeft(node.left);
            }
            if (node.right != null) {
                runStraightLeft(node.right);
            }
        }


        public void writeNums() throws IOException {
            try (PrintWriter pw = new PrintWriter("output.txt")) {
                for (int i : mylist) {
                    pw.println(i);
                }
            }
        }
    }


    public static void main(String[] args) {
        new Thread(null, new MyMain(), "", 64 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        try {
            Tree obj = new Tree();
            obj.makeTree();
            obj.delete();

            obj.runTreeSL();
            obj.writeNums();
        } catch (FileNotFoundException e) {
            System.out.println("FNF");
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }

}