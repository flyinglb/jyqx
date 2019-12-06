

#include <ansi.h>

inherit F_CLEAN_UP;

mixed main(object me)
{
	object *ob;
	int i, ppl_cnt, cnt, wcnt = 0;

	ob = filter_array(objects(), (: userp :));
	ppl_cnt = 0;
	cnt = 0;
	i = sizeof(ob);
	while( i-- ) {
        if (!environment(ob[i])) continue;
	        if (wizardp(ob[i])) wcnt++;
		else if (interactive(ob[i])) ppl_cnt++;
		else cnt++;
	}
	
	write("\n"+MUD_NAME+"Ŀǰ���� "+wcnt+" λ��ʦ�� "+ppl_cnt+" λ��������У�"+cnt+" λ��Ҷ����С�
ϵͳ������"+query_load_average()+"��
���ڵ� time() �ǣ�" + time() + "��
���ڵ� uptime() �ǣ�" + uptime() + "��\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : users

���ָ������г�Ŀǰ�����������

���ָ� who
HELP
	);
	return 1;
}
