// /u/beyond/mr/hssg.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",MAG"��ʩˮ��"NOR);
         set("long",
"����Ǿ��������Ĺ���Ľ�ݵĻ�ʩˮ�������˵�кܶ�����������\n"
"���Ծõ��书��ֻ��ǽ����һ�������(shujia)����������˸����伮��\n"
);
         set("exits",([
             "south" : __DIR__"jiabi",
]));
         set("item_desc", ([
             "shujia" : "����ϸ������ɵ��书�ؼ�(miji)�����̲�ס������һ���ͷ���������\n",
]));
}

int init()
{
        add_action("do_kan","kan");  
        add_action("do_kan","du");
        add_action("do_kan","yandu");
        add_action("do_kan","lingwu");
        add_action("do_kan","study");
}

int do_kan(string arg)
{         object me;
        me = this_player();
 if ( !living(this_player()) || arg != "miji" )
                 return 0;
        if (me->query("family/master_name")!="Ľ�ݸ�")
        if (me->query("family/master_name")!="Ľ�ݲ�")
        return 0;
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)������ת���ưɡ�\n");
        if ( (int)me->query_skill("literate", 1) < 150)
		 return notify_fail("��Ķ���д�ּ��𲻹����޷��������ת���Ƶľ���֮����\n");
        if ( (int)me->query_skill("parry", 1) < 160 )
                 return notify_fail("ƾ�����ڵ��мܹ����޷�����ת������ô������书��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 170)
        return notify_fail("�㿴�˰�������ϵ��书�ؼ������������˵̫����ˣ�\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) > 200)
        return notify_fail("��ϲ��ϲ�����Ѿ��ڻ��ͨ�˶�ת���Ƶľ���֮����\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û������������ת�����ˣ�\n");              
        return 1;}
	if( (int)me->query("potential", 1) < 2 ) {
		write("���Ѿ�û��Ǳ��������ѧϰ��ת�����ˡ�\n");
		return 1; }
		  me->receive_damage("jing", random(50));
        message_vision("$N���ڵ�ͷ��˼�йض�ת���Ƶ��������ѡ�\n", me);  
        write("�㾲�������и������ɵ��书�ؼ���ڤڤ֮����Ķ�ת�����ֽ���һ����\n");
               me->improve_skill("douzhuan-xingyi", me->query_skill("literate",1)/2);
		  me->add("potential", -2);       
         return 1;
}

