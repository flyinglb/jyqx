// /u/beyond/mr/houting.c
// this is made by beyond
// last update 1997/JULY/5

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @LONG
������Ľ�ݼ�����������ĵط�������Ľ�ݵ�����ò�Ҫ������������
�������аڷ���һ���㰸������ڷ���һ����λ����(paizi)��������ǽ�Ϲ�
��һ�����񳯷�ͼ����ǽ�Ϲ���һ�ڱ����������������һ���᷿��������
���á�
LONG
    );
         set("item_desc",([
             "paizi" : "Ľ������������λ\n",  
             "sword" : "����һ�������ı�����͸�ű���ɫ��\n",
             "baojian" : "����һ�������ı�����͸�ű���ɫ��\n",
]));
         set("exits",([
             "east" : __DIR__"xiangfang2",
             "west" : __DIR__"xiangfang3",                    
             "south" : __DIR__"neitang",
             "north" : __DIR__"dating",
]));

         setup();
//         replace_program(ROOM);
}
             
void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_ketou", "�ݼ�");
}             

int do_ketou()
{
    mapping fam; 
    object me, ob, sword;

    me = this_player();
    ob = this_object();    
        if ( !present("douzhuan xingyi",me) || 
             !(fam = me->query("family")) || 
             fam["family_name"] != "����Ľ��" ||
             me->query("combat_exp") < 100000 )
             return 0;
           
        if ( me->query_temp("Ľ��/ketou") == 20 ) {    
             sword = new("/d/mr/obj/biyu-jian");                          
                if(!clonep(sword)) {
                        message("vision","�㲻�������������ƺ��ѱ��򿪹���\n", me);
                        me->delete_temp("Ľ��/ketou");
                        return 1;
                        }
                if (clonep(sword) && sword->violate_unique()){ 
                        destruct(sword);   
                        message("vision","�㲻�������������ƺ��ѱ��򿪹��ˡ�\n", me);
                        me->delete_temp("Ľ��/ketou");
                        return 1;
                        }  
                message("vision","ֻ��������һ�������������һ�Ѻ��������ı�����\n",me);
                        sword->move(ob);
                        destruct(present("douzhuan xingyi",me));
                        me->delete_temp("Ľ��/ketou");
                        return 1;
         }
        else {
                me->add_temp("Ľ��/ketou", random(2));
                message_vision("$N����������������ǰ���˸���ͷ��\n", me);
                return 1;
                }
}       

