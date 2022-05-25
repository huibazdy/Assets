#include<iostream>
#include<vector>

int main()
{
	vector<int> inputs;
	int val;

	while(cin>>val)
	{
		inputs.push_back(val);
		if(cin.get() == '\n')
			break;
	}

	for(int i = 0; i < inputs.size(); i++)
		cout<<inputs[i]<<" ";

	return 0;
}
