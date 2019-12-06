// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

	if( !ob->is_character() )
		return notify_fail("���𲻶�����\n");

	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");

	if( me->query("family/privs")==-1
	&&	(string)me->query("family/family_name")==(string)ob->query("family/family_name") ) {
		message_vision("\n$N����$n˵�����ӽ���������Ҳ������"
			+ me->query("family/family_name") + "�ĵ����ˣ����߰ɣ�\n\n",
			me, ob);
		tell_object(ob, "\n�㱻" + me->query("family/title") + "�����ʦ���ˣ�\n\n");
	} else if( ob->is_apprentice_of(me) ) {
		message_vision("\n$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n\n",
			me, ob);
		tell_object(ob, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");

	ob->delete("family");
//	ob->delete("title");
	ob->set("title", "��ͨ����");
	ob->set("score", 0);
	skills = ob->query_skills();

	if( mapp(skills) ) {
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] /= 2;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : expell|kaichu <ĳ��>
 
���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������м��ܶ��ή��ԭ��
��һ�룬�����ۺ�����һ������㣬�����һ�����������һ����������
���ء��Ĵ���������ڿ���һ������֮ǰ����������ǡ�
 
HELP
	);
	return 1;
}
