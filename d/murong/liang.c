// /u/beyond/mr/liang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short",HIW"����"NOR);
       set("long",@long
���Ǳ�ˮͤ�ϵķ��������滭����ϣ��Źֵ��ַ���
long
        );                                           
        set("item_desc",([
  "zihua" : "���滭���˸�����ֵ��ַ���\n"
        ]));
        setup();
}
void init()
{
add_action("do_study","lingwu");                           
add_action("do_study","kan");                            
add_action("do_study","study");
add_action("do_jump","jump");
}

int do_study(string arg)
{         object me;
	me = this_player();
        if (arg != "zihua" )
                 return 0;
    if (me->query("family/master_name")!="Ľ�ݸ�" && me->query("family/master_name")!="Ľ�ݲ�")
         return 0;
 
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)������ת���ưɡ�\n");
        if ( (int)me->query_skill("parry", 1) < 120 )
		 return notify_fail("ƾ�����ڵ��мܹ����޷�����ת������ô������书��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 130)
        return notify_fail("������ֻ����˰��죬���������˵̫����ˣ�ʲô��û��ѧ����\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) > 170)
        return notify_fail("������ֻ����˰��죬���������˵�Ѿ�̫ǳ�ˣ�ʲô��û��ѧ����\n");
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("shenyuan-gong",1)+30)){
write("���������Ԫ�������������ٽ��и���һ�����ߡ�\n");
return 1;
}
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("literate",1)+30)){
write("������Ķ���д�ֻ����������ٽ��и���һ�����ߡ�\n");
return 1;
}
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û������������ת�����ˣ�\n");              
        return 1;
}
        me->receive_damage("jing", random(45));
        message_vision("$N���ڵ�ͷ��˼�йض�ת���Ƶ��������ѡ�\n", me);  
        write("������ֻ����˰��죬ڤڤ֮����Ķ�ת�����ֽ���һ����\n");
                  me->improve_skill("douzhuan-xingyi", me->query("int"));       
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
            
                    write("�����������˷�����\n");
                    message("vision",
                             me->name() + "һ���������˷�����\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"bishuiting");
                    message("vision",
                             me->name() + "���˹�����\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

