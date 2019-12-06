// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int skill_lvl, lvl=0;
	string skill;

	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
	   sscanf(arg, "%s", skill)!=1)
		return notify_fail("��Ҫ������һ��ܣ�\n");
	skill_lvl = me->query_skill(skill,1);
	if( lvl <0 )
		return notify_fail("���ܼ�����Ϊ����\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("�������Ⱑ���㲻�����⼶���ᡣ\n");
	if( lvl > skill_lvl || lvl > 400)
		return notify_fail("������ܲ�û��ѧ���������\n");
	if( !me->delete_skill(skill) )
		return notify_fail("�㲢û��ѧ������ܡ�\n");
	write("�������������ѧϰ" + to_chinese(skill) + "��\n");
	if( lvl > 0 ) me->set_skill(skill, lvl);
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������> [����]

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

��������ڷ�������ʱ�����뼶�𣬽�ֻ������ָ������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}