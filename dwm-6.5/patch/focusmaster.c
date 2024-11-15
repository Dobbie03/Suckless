void
focusmaster(const Arg *arg)
{
	Client *master;
	Monitor *m = selmon;
	int i;

	if (m->nmaster < 1)
		return;
	if (!m->sel || (m->sel->isfullscreen && lockfullscreen))
		return;

	master = nexttiled(m->clients);

	if (!master)
		return;

	for (i = 0; !(m->tagset[m->seltags] & 1 << i); i++);
	i++;

	if (m->sel == master) {
		if (m->tagmarked[i] && ISVISIBLE(m->tagmarked[i]))
			focus(m->tagmarked[i]);
	} else {
		m->tagmarked[i] = m->sel;
		focus(master);
	}
	restack(m);
}
