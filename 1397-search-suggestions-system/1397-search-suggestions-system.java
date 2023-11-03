class Solution {
		static final int ALPHABET_SIZE = 26;
	
		static class TrieNode
		{
			TrieNode[] children = new TrieNode[ALPHABET_SIZE];
		
			boolean isEndOfWord;

            String thatWord;
			
			TrieNode(){
				isEndOfWord = false;
				for (int i = 0; i < ALPHABET_SIZE; i++)
					children[i] = null;
			}
		};

		public void insert(String key) {
        int level;
				int length = key.length();
				int index;
	
				TrieNode pCrawl = root;
			
				for (level = 0; level < length; level++)
				{
					index = key.charAt(level) - 'a';
					if (pCrawl.children[index] == null)
						pCrawl.children[index] = new TrieNode();
			
					pCrawl = pCrawl.children[index];
				}
	
				// mark last node as leaf
				pCrawl.isEndOfWord = true;
                pCrawl.thatWord = key;
        
    }

		public List<String> search(String key)
	{
		int level;
		int length = key.length();
		int index;
		TrieNode pCrawl = root;
	
		for (level = 0; level < length; level++)
		{
			index = key.charAt(level) - 'a';
	
			if (pCrawl.children[index] == null)
				return new ArrayList();
	
			pCrawl = pCrawl.children[index];
		}

		int cnt=3;
		List<String> ans = new ArrayList();
		while (cnt!=0){
			ans = getWord(pCrawl, key, new ArrayList());
			cnt--;
		}

		return ans;
	}
	
	static TrieNode root;


	public List<String> getWord(TrieNode root, String currentWord, List<String> listWord) {

		if (root.isEndOfWord) {
			if (listWord.size() != 3) {
				listWord.add(currentWord);
			}
			// return listWord;
		}

		for (int i=0; i<26; i++) {
			if (root.children[i] != null) {
				char x = (char)('a' + i);
				getWord(root.children[i], currentWord+x, listWord);
			}
		}
		return listWord;

	}
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        root = new TrieNode();
				for (int i=0; i<products.length; i++){
						insert(products[i]);
				}

				List<List<String>> ans = new ArrayList();

				for (int i=1; i<=searchWord.length(); i++) {
						System.out.println(searchWord.substring(0, i));
						List<String> lessgo = search(searchWord.substring(0, i));
						System.out.println(lessgo);
						ans.add(lessgo);
				}
				return ans;
    }
}