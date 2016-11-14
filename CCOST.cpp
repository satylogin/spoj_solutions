#include <bits/stdc++.h>

using namespace std;

#define ll long long int

struct node {
	int x, y, x1, val, type;
};

int comp(const void *a, const void *b)
{
	node *p, *q;
	p = (node *) a;
	q = (node *) b;

	if (p->y == q->y) {
		if (p->x == q->x) {
			if ((p->type == 1 && q->type == 2) || (p->type == 2 && q->type == 1)) {
				return ((p->type == 1) ? 1 : -1);
			} else if ((p->type == 1 && q->type == 3) || (p->type == 3 && q->type == 1)) {
				return ((p->type == 1) ? -1 : 1);
			} else {
				return 0;
			}
		} else {
			return (p->x - q->x);
		}
	} else {
		return (p->y - q->y);
	}
}

ll BIT[10000005];
node ask[100001 + 500001];
ll out[500001];

void insert(int x, int val)
{
	for (; x <= 10000001; x += (x&-x)) 
		BIT[x] += val;
}

ll query(int x)
{
	ll ret = 0;
	for (; x > 0; x -= (x&-x)) 
		ret += BIT[x];
	return ret;
}

int main()
{
	int t, n, m, c, i, j, k, x, y, z, x1, y1;

	scanf("%d", &t);
	while (t--) {
		c = 0;
		memset(BIT, 0, sizeof(BIT));
		memset(out, 0, sizeof(out));
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d %d %d", &x, &y, &z);
			ask[c].x = x+1;
			ask[c].y = y+1;
			ask[c].type = 1;
			ask[c].val = z;
			c++;
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d %d %d %d", &x, &y, &x1, &y1);
			ask[c].x = x+1;
			ask[c].y = y+1;
			ask[c].type = 2;
			ask[c].val = i;
			ask[c].x1 = x1+1;
			c++;

			ask[c].x = x1+1;
			ask[c].y = y1+1;
			ask[c].type = 3;
			ask[c].val = i;
			ask[c].x1 = x+1;
			c++;
		}

		qsort(ask, c, sizeof(node), comp);

		for (i = 0; i < c; ++i) {
			if (ask[i].type == 1) {
				insert(ask[i].x, ask[i].val);
			} else if (ask[i].type == 2) {
				out[ask[i].val] -= (query(ask[i].x1) - query(ask[i].x - 1));
			} else if (ask[i].type == 3) {
				out[ask[i].val] += (query(ask[i].x) - query(ask[i].x1 - 1));
			}
		}

		for (i = 0; i < m; ++i) {
			printf("%lld\n", out[i]);
		}
	}

	return 0;
}
