#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 256

struct SuffixTreeNode {
	struct SuffixTreeNode *children[MAX_CHAR];

	struct SuffixTreeNode *suffixLink;

	int start;
	int *end;

	int suffixIndex;
};

typedef struct SuffixTreeNode Node;

class SuffTree {
public:
	char *text; 
	Node *root = NULL; 


					
	Node *lastNewNode = NULL;
	Node *activeNode = NULL;


	int activeEdge = -1;
	int activeLength = 0;


	int remainingSuffixCount = 0;
	int leafEnd = -1;
	int *rootEnd = NULL;
	int *splitEnd = NULL;
	int size = -1; 

	Node *newNode(int start, int *end)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		int i;
		for (i = 0; i < MAX_CHAR; i++)
			node->children[i] = NULL;


		node->suffixLink = root;
		node->start = start;
		node->end = end;


		node->suffixIndex = -1;
		return node;
	}

	int edgeLength(Node *n) {
		if (n == root)
			return 0;
		return *(n->end) - (n->start) + 1;
	}

	int walkDown(Node *currNode)
	{

		if (activeLength >= edgeLength(currNode))
		{
			activeEdge += edgeLength(currNode);
			activeLength -= edgeLength(currNode);
			activeNode = currNode;
			return 1;
		}
		return 0;
	}

	void extendSuffixTree(int pos)
	{

		leafEnd = pos;


		remainingSuffixCount++;


		lastNewNode = NULL;

		while (remainingSuffixCount > 0) {

			//printf("hello1");
			if (activeLength == 0)
				activeEdge = pos; 

							
			if (activeNode->children[text[activeEdge]] == NULL)
			{
				//printf("hello2");
				activeNode->children[text[activeEdge]] =
					newNode(pos, &leafEnd);

			
				if (lastNewNode != NULL)
				{
					//printf("hello3");
					lastNewNode->suffixLink = activeNode;
					lastNewNode = NULL;
				}
			}
			
			else
			{
				
				//printf("hello4");
				Node *next = activeNode->children[text[activeEdge]];
				if (walkDown(next))
				{
					//printf("hello5");
					continue;
				}
				
				if (text[next->start + activeLength] == text[pos])
				{
					
					if (lastNewNode != NULL && activeNode != root)
					{
						lastNewNode->suffixLink = activeNode;
						lastNewNode = NULL;
					}

					activeLength++;
				
					break;
				}
			
				splitEnd = (int*)malloc(sizeof(int));
				*splitEnd = next->start + activeLength - 1;

				Node *split = newNode(next->start, splitEnd);
				activeNode->children[text[activeEdge]] = split;

				split->children[text[pos]] = newNode(pos, &leafEnd);
				next->start += activeLength;
				split->children[text[next->start]] = next;

				if (lastNewNode != NULL)
				{
					//printf("hello9");
					lastNewNode->suffixLink = split;
				}

				//printf("hello10");
				lastNewNode = split;
			}

	
			remainingSuffixCount--;
			if (activeNode == root && activeLength > 0) 
			{
				activeLength--;
				activeEdge = pos - remainingSuffixCount + 1;
			}
			else if (activeNode != root) 
			{
				activeNode = activeNode->suffixLink;
			}
		}
	}

	void print(int i, int j)
	{
		int k;
		for (k = i; k <= j; k++)
			printf("%c", text[k]);
	}


	void setSuffixIndexByDFS(Node *n, int labelHeight)
	{
		if (n == NULL)  return;

		if (n->start != -1)
		{
			
		}
		int leaf = 1;
		int i;
		for (i = 0; i < MAX_CHAR; i++)
		{
			if (n->children[i] != NULL)
			{
				
				leaf = 0;
				setSuffixIndexByDFS(n->children[i], labelHeight +
					edgeLength(n->children[i]));
			}
		}
		if (leaf == 1)
		{
			n->suffixIndex = size - labelHeight;
			
		}
	}

	void freeSuffixTreeByPostOrder(Node *n)
	{
		if (n == NULL)
			return;
		int i;
		for (i = 0; i < MAX_CHAR; i++)
		{
			if (n->children[i] != NULL)
			{
				freeSuffixTreeByPostOrder(n->children[i]);
			}
		}
		if (n->suffixIndex == -1)
			free(n->end);
		free(n);
	}

	
	void buildSuffixTree()
	{
		size = strlen(text);
		printf("%d\n",size);
		int i;
		rootEnd = (int*)malloc(sizeof(int));
		*rootEnd = -1;

		
		root = newNode(-1, rootEnd);

		activeNode = root;

		
		for (i = 0; i < size; i++) {

			
			extendSuffixTree(i);
		}
			
		int labelHeight = 0;
		printf("extend done");
		setSuffixIndexByDFS(root, labelHeight);
	}

	int traverseEdge(char *str, int idx, int start, int end)
	{
		int k = 0;

		for (k = start; k <= end && str[idx] != '\0'; k++, idx++)
		{
			if (text[k] != str[idx])
				return -1;  
		}
		if (str[idx] == '\0')
			return 1;  
		return 0;  
	}

	int doTraversalToCountLeaf(Node *n)
	{
		if (n == NULL)
			return 0;
		if (n->suffixIndex > -1)
		{
			printf("\nFound at position: %d", n->suffixIndex);
			return 1;
		}
		int count = 0;
		int i = 0;
		for (i = 0; i < MAX_CHAR; i++)
		{
			if (n->children[i] != NULL)
			{
				count += doTraversalToCountLeaf(n->children[i]);
			}
		}
		return count;
	}

	int countLeaf(Node *n)
	{
		if (n == NULL)
			return 0;
		return doTraversalToCountLeaf(n);
	}

	int doTraversal(Node *n, char* str, int idx)
	{
		if (n == NULL)
		{
			return -1; // no match
		}
		int res = -1;
		
		if (n->start != -1)
		{
			res = traverseEdge(str, idx, n->start, *(n->end));
			if (res == -1)
				return -1;
			if (res == 1) 
			{
				/*if (n->suffixIndex > -1)
					printf("\nsubstring count: 1 and position: %d",
						n->suffixIndex);
				else*/
					//printf("\nsubstring count: %d", countLeaf(n));
					int x = countLeaf(n);
				return 1;
			}
		}
		
		idx = idx + edgeLength(n);
		
		if (n->children[str[idx]] != NULL)
			return doTraversal(n->children[str[idx]], str, idx);
		else
			return -1;
	}

	void checkForSubString(char* str)
	{
		int res = doTraversal(root, str, 0);
		if (res == 1)
			printf("\nPattern <%s> is a Substring\n", str);
		else
			printf("\nPattern <%s> is NOT a Substring\n", str);
	}
};
