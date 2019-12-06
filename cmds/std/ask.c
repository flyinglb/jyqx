// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
//        mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}
