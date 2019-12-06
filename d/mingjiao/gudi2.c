// Room: /d/mingjiao/gudi2.c
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���عȵ�");
	set("long", @LONG
�����Ƕ�����Ҳ�ƵĴ�ɽ�ڡ���ǰ����ãã�ƺ�������ȥ·��
ɽʯ��Ӳ�ޱȣ��㿴���ұ���һ�������(tree)�����ɽ�ں�����
�ƺ��и�Сɽ��(dong)��
LONG );
	set("outdoors", "mingjiao");
	set("item_desc", ([
		"dong": "һ����֪��ǳ��ɽ����\n",
		"tree": "һ��ͦ�ν�˶��������\n",
	]));
	setup();
}
void init()
{
	add_action("do_enter","enter");
	add_action("do_climb","climb");
}
int do_enter(string arg)
{
        object me = this_player();
        int n = me->query("str");
        if( !arg || arg != "dong")
        {
                write("�����ʲôѽ?\n");
                return 1;
        }
        message_vision("$N������һ�������������Ŷ�����������\n", me);
        if(n < 20 || wizardp(me))
        {
                message_vision("$N�������ɣ�����ǰ��͸�����������д�ϲ�������ʩ������ǰ�С�\n", me);
                me->move(__DIR__"gudi3");
        }
        else
        {
                message_vision(HIR
"$N��ŭ֮�£�����˫�磬��ǰһ�������ӹ�Ȼǰ���˳�����������ǰ�У�ȴ������\n", me);
                message_vision(
"�ܣ���Ӳ��ʯ��ѹ�����ؿڱ��ģ���Ȼ��Ҳ����������$N��Ϣ���ܣ�ֻ�ú��ˣ�������\n", me);
                message_vision(
"��Ƕ�ڼ�ʯ֮�У�ǰ�����ǲ��ܣ�����ȴҲ�Ѳ��ã���һ��$N�ŵû����ɢ���߾���ƽ\n", me);
                message_vision(
"֮����˫����ʯ�����ƣ����Ӳ����˳����;����ؿ�һ���ʹ������������һ���߹ǡ�\n"NOR, me);
                me->receive_damage("qi",15);
                me->receive_wound("qi",10);
        }
        return 1;
}
int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg != "tree")
        {
                write("�����ʲôѽ?\n");
                return 1;
        }
        message_vision("$N����������ҡ����ҡ�������Ƿ��ʵ��\n", me);
        message_vision("$N��Ȼһ��ʧ�֣���������ֱ����ȥ��\n", me);
        me->move(__DIR__"shanjiao");
        me->receive_damage("qi",100 - me->query_dex());
        me->receive_wound("qi",100 - me->query_dex());
        me->unconcious();
        return 1;
}
