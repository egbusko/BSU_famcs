
import java.io.*;
import java.util.ArrayList;
import java.util.List;



class Tre {
    static class Node {
        int key;
        int height = 0;
        Node left;
        Node right;

        int maxSemPLength = 0;
        int leafNum = 0;
        int pathsNum = 1;
        int pathsNumUp = 0;

        public Node(int key) {
            this.key = key;
        }
    }

    Node root;
    int maxSemipathLength = 0;
    int maxNKey = Integer.MAX_VALUE;

    public void insert(int value) {
        if (root == null) {
            root = new Node(value);
            return;
        }

        Node node = root;
        while (true) {
            if (value < node.key) {
                if (node.left == null) {
                    node.left = new Node(value);
                    return;
                } else {
                    node = node.left;
                }
            } else if (value > node.key) {
                if (node.right == null) {
                    node.right = new Node(value);
                    return;
                } else {
                    node = node.right;
                }
            } else {
                return;
            }
        }
    }

    public Node deleteRecursive(Node current, long value) {
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
                current.right = deleteRecursive(current.right, min);
                return current;
            }
        }
        if (value < current.key) {
            current.left = deleteRecursive(current.left, value);
            return current;
        }
        current.right = deleteRecursive(current.right, value);
        return current;
    }


    private Node findMin(Node current) {
        if (current.left != null) {
            return findMin(current.left);
        } else {
            return current;
        }
    }

    public void getHeight(Node node) {
        if (node == null) return;

        getHeight(node.left);
        getHeight(node.right);

        if (node.left == null && node.right == null) {
            node.height = 0;
            node.leafNum = 1;
        } else if (node.left != null && node.right == null) {
            node.height = node.left.height + 1;
            node.maxSemPLength += node.left.height + 1;
            node.leafNum = node.left.leafNum;
        } else if (node.left == null && node.right != null) {
            node.height = node.right.height + 1;
            node.maxSemPLength += node.right.height + 1;
            node.leafNum = node.right.leafNum;
        } else if (node.left != null && node.right != null) {
            node.height = Math.max(node.left.height, node.right.height) + 1;
            node.maxSemPLength += node.left.height + node.right.height + 2;

            if (node.left.height == node.right.height) {
                node.leafNum = node.left.leafNum + node.right.leafNum;
            } else if (node.left.height > node.right.height) {
                node.leafNum = node.left.leafNum;
            } else {
                node.leafNum = node.right.leafNum;
            }
        }
        if (node.maxSemPLength > maxSemipathLength) {
            maxSemipathLength = node.maxSemPLength;
        }
    }

    public void setAB(Node node) {
        if (node == null) return;

        if (node.maxSemPLength == maxSemipathLength) {
            if (node.left != null) node.pathsNum *= node.left.leafNum;
            if (node.right != null) node.pathsNum *= node.right.leafNum;
        } else {
            node.pathsNum = 0;
        }

        if (node == root) node.pathsNumUp = 0;
        if (node.left == null

                && node.right != null) {
            node.right.pathsNumUp = node.pathsNum + node.pathsNumUp;
        }
        if (node.right == null && node.left != null) {
            node.left.pathsNumUp = node.pathsNum + node.pathsNumUp;
        }
        if (node.left != null && node.right != null) {
            if (node.left.height > node.right.height) {
                node.left.pathsNumUp = node.pathsNumUp + node.pathsNum;
                node.right.pathsNumUp = node.pathsNum;
            } else if (node.left.height < node.right.height) {
                node.left.pathsNumUp = node.pathsNum;
                node.right.pathsNumUp = node.pathsNum + node.pathsNumUp;
            } else {
                node.left.pathsNumUp = node.pathsNum + (node.left.leafNum * node.pathsNumUp / node.leafNum);
                node.right.pathsNumUp = node.pathsNum + (node.right.leafNum * node.pathsNumUp / node.leafNum);
            }
        }


        setAB(node.left);
        setAB(node.right);
    }

    public void getDel(Node node) {
        if (node == null) return;
        if ((node.pathsNumUp + node.pathsNum) % 2 == 0 && node.key < maxNKey) {
            maxNKey = node.key;
        }
        getDel(node.left);
        getDel(node.right);
    }

    void preOrderTravers(Node root, FileWriter ps) throws IOException {
        if (root != null) {
            ps.write(root.key + "\n");
            System.out.println(root.key + " h==" + root.height
                    + " msl==" + root.maxSemPLength + " n_leaves==" + root.leafNum
                    + " a==" + root.pathsNumUp + " b==" + root.pathsNum);
            if (root.left != null) preOrderTravers(root.left, ps);
            if (root.right != null) preOrderTravers(root.right, ps);
        }
    }

}


public class OtherClass implements Runnable {

    public static void main(String[] args) {
        new Thread(null, new OtherClass(), "", 128 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        Tre tree = new Tre();
        try {
            BufferedReader reader = new BufferedReader(new FileReader("tst.in"));
            String t;

            while ((t = reader.readLine()) != null) {
                tree.insert(Integer.parseInt(t));
            }

            tree.getHeight(tree.root);
            tree.setAB(tree.root);
            tree.getDel(tree.root);
            if (tree.maxNKey != Integer.MIN_VALUE)
                tree.deleteRecursive(tree.root, tree.maxNKey);

            System.out.println(tree.maxNKey);

            FileWriter ps = new FileWriter("tst.out");
            tree.preOrderTravers(tree.root, ps);
            ps.close();

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

   /* public void runBackLeftHei(Tree.Node node) {
        if (node == null) return;
       *//* int h_left = -1;
        int h_right = -1;*//*
        //if (node.left != null) {
        runBackLeftHei(node.left);
        //}
        //if (node.right != null) {
        runBackLeftHei(node.right);
        //}

        if (node.left == null && node.right == null) {
            node.height = 0;
            //node.msl = 0;
            node.num_leaves = 1;
        } else if (node.left != null && node.right == null) {
            node.height = node.left.height + 1;
            node.msl = node.left.height + 1;
            node.num_leaves = node.left.num_leaves;
        } else if (node.left == null && node.right != null) {
            node.height = node.right.height + 1;
            node.msl = node.right.height + 1;
            node.num_leaves = node.right.num_leaves;
        }else if (node.left != null && node.right != null) {
            node.height = Math.max(node.left.height, node.right.height) + 1;
            node.msl = node.left.height + node.right.height + 2;

            if (node.left.height == node.right.height) {
                node.num_leaves = node.right.num_leaves + node.left.num_leaves;
            } else if (node.left.height > node.right.height) {
                node.num_leaves = node.right.num_leaves;
            }else {
                node.num_leaves = node.left.num_leaves;
            }

        }
        if (node.msl > maxSemipathLength) {
            maxSemipathLength = node.msl;
        }
        //return node.height;
    }*/
