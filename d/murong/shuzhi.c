// /u/beyond/mr/shuzhi.c
// this is made by beyond
// update 1997.6.20
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"����"NOR);
       set("long",@long
������֦ͷ��һƬ���̵Ĳݵ�ӳ�������������Ǳ���һ֦�������֦��
��֪�ܲ���Խ��ȥ��
long);
       setup();
}
void init()
{
        add_action("do_jump","jump");
         add_action("do_yue","yue");
}

int do_yue(string arg)
{
        object me;
	
        me = this_player();
	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ((int)me->query("jing")<30)
		return notify_fail("��̫���ˣ��޷����������ˣ�\n");
    if ((int)me->query_skill("dodge",1)>201)
		return notify_fail(
	"������֦��Ծ����ȥ������������ȥ���������Ṧû���İ�����\n");

        if ((int)me->query_skill("dodge", 1) < 20 )
		return notify_fail(
			"��Ϊ���Ǳߵ���֦̫Զ��ʹ���޷�Խ��ȥ�����ˤ����\n");
	
me->receive_damage("jing", 25);
	me->improve_skill("dodge", me->query("int"));

	message_vision("$N����֦�����ص���Ծ��\n", me);
	me->move(__DIR__"shuzhi");

	return 1;	
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="down") 
        return notify_fail("��Ҫ����ȥ��\n");
        if( arg=="down")
                   {
            
                    write("��˳����֦������ȥ��\n");
                    message("vision",
me->name() +"˳����֦������ȥ��\n",
                    environment(me), ({me}) );
                    me->move(__DIR__"liulin3");
                    message("vision",
   me->name() +"����֦��������ȥ��\n",
                    environment(me), ({me}) );
                   }
                return 1;
            }

