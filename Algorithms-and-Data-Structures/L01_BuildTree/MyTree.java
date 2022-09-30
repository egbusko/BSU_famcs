public class MyTree {
    public class Node {
        public int key;
        public MyMain.Tree.Node left;
        public MyMain.Tree.Node right;

        public Node(int key) {
            this.key = key;
        }
    }

    private MyMain.Tree.Node root;

    public void insert(int x) {
        root = doInsert(root, x);
    }

    private static MyMain.Tree.Node doInsert(MyMain.Tree.Node node, int x) {
        if (node == null) {
            //return new MyMain.Tree.Node(x);
        }
        if (x < node.key) {
            node.left = doInsert(node.left, x);
        } else if (x > node.key) {
            node.right = doInsert(node.right, x);
        }
        return node;
    }
}