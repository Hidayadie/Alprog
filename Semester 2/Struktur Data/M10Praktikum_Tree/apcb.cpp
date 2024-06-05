void drawTree(node* root) {
    if (root == NULL)
        return;
    int level = 1, count = 10;  
   	for (int a = 0; a < 10; a++) {
	    for (int i = 0; i < count; i++) {
			cout << " ";
			
		}
			//cout << ((a % 2 == 0) ? root->data : );
		if (a % 2 == 0) {
			int o = 0;
			do {
			
				cout << root->data;
				cout << "   ";
				//cout << root->data;
				o++;
			} while (o < level);
		}
			
		if (root->left != NULL) {
			cout << ((a % 2 == 0) ? ' ' : '/');
		}
		
		if (root->right != NULL) {
			cout << " ";
			cout << ((a % 2 == 0) ? ' ' : '\\');
		}
		
		count--;
		level++;
		cout << "\n";
		//drawTree(root->left);	
	}
		
    
}
