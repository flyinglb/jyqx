// /u/beyond/mr/guifang.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIY"�뷿"NOR);
         set("long",@long
������ɽׯׯ��Ů���Ĺ뷿������͸��һ�����˵���Ů���㣬��������
�ڹ뷿��һ�ǰڷ���һ����ױ̨��̨�ϰ���һЩŮ���õ���֬�ۺ�����ͿĨ
�촽����ۣ��Լ�һƿ��¶�����ݵ���һ�ǰڷ���һ�Ź봲��һ����ɴ�ʹ�
������ǽ����һ��������һ�ȴ���(window)���š�
long);
         set("no_fight",1); 
set("item_desc",([
"window" : "��̨����һ��С�ɵĽ�ӡ(sign)��\n",
"sign" : "��ֻ�ɰ���С��ӡ������ȥ��һ������Ĳ������㲻ס��̤��ȥ��\n",
]));
         set("exits",([
              "west" : __DIR__"cl4-4",
]));
         setup();
//       replace_program(ROOM);
}
                                                           
int init()
{
	add_action("do_ta","ta");
	add_action("do_jump","jump");
}

int do_ta(string arg)
{         object me;
	me = this_player();
 if ( !living(this_player()) || arg != "sign" )
                 return 0;
        if ((int)me->query_skill("dodge", 1) > 31)
        return notify_fail("��̤�Ͽɰ���С��ӡ�������Ѿ��޷������Ļ����Ṧ�ˡ�\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�̧������ˣ�\n");              
        return 1;
}
        me->receive_damage("jing", random(25));
        message_vision("$N����̤�Ŵ�̨�ϵ�С��ӡ��\n", me);  
        write("��̤��С��ӡ��ʹ��Ļ����Ṧ�ֽ���һ����\n");
                  me->improve_skill("dodge", me->query("int"));       
         return 1;
} 

int do_jump(string arg)
{       object me;
        me = this_player();
        if (arg !="window") 
        return notify_fail("��Ҫ��ʲô��\n");
        if( arg=="window")
        {          
             write("��һ�����Ӵ���������ȥ��\n");
                    message("vision",
             me->name() + "�Ӵ���������ȥ��\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"ytyuan1");
                    message("vision",
                  me->name() + "��ǽ�ϵĴ���������������\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

        

