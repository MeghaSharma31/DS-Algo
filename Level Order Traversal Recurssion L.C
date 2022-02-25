Map Solution :
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        List<List<Integer>> res = new ArrayList<>();
        int heightoftree = height(root);
        levelOrderHelper(root, 0, heightoftree,map);
        for (Map.Entry<Integer,List<Integer>> entry : map.entrySet()) {
           res.add(entry.getValue()); 
        }
        return res;
    }
    public void levelOrderHelper(TreeNode root, int level, int height, HashMap<Integer, List<Integer>> map) {
        if(root == null)
            return;
        if(level == height)
            return;
        if(!map.containsKey(level)) {
            List<Integer> res = new ArrayList<>();
            res.add(root.val);
            map.put(level,res );
        }
        else {
             List<Integer> res = map.get(level);
            res.add(root.val);
            map.put(level, res);
        }
        levelOrderHelper(root.left, level+1, height, map);
        levelOrderHelper(root.right, level+1,height,map);
    }    
    public int height(TreeNode root) {
        if(root == null)
            return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }
}

A quite different/good solution :
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        int heightoftree = height(root);
        for(int i = 0;i<heightoftree;i++) {
            List<Integer> res = new ArrayList<>();
            storeAtaGivenLevel(root, i, res);
            ans.add(res);
        }
        return ans;
    }
   
    public int height(TreeNode root) {
        if(root == null)
            return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }
    
    
    public void storeAtaGivenLevel(TreeNode root, int level, List<Integer> res) {
        if(root == null || level < 0)
            return;
        if(level == 0)
        {  res.add(root.val);
            return;
        }
        storeAtaGivenLevel(root.left, level-1,res);
        storeAtaGivenLevel(root.right, level-1,res);
        
    }
}


