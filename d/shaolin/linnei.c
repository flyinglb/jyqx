// linnei.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set ("long",@long
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��
ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ��Ա���һ��ɽ����������ʯ(stone)��ס�ˡ�
long);
         set("item_desc", ([
             "stone" : "һ��޴���ʯ���Ѷ��ڶ�ס�ˡ�\n",
]));

setup();
}

void init()
{
    add_action("do_break", "break");
    add_action("do_jump","zuan");
}
int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="stone" ) {
                write("��Ҫ����ʲô�Ķ�����\n");
                return 1;
        }

  message_vision(
   "$N����һ������˫��ͬʱ�ĳ���\n", this_player());

  if (n>=500) {
        message_vision(
 "$Nֻ��һ�����䡱��һ����$N����ʯ���ˣ�������һ�����ڡ�\n", this_player());
        set("exits/enter", __DIR__"dongnei");
        this_player()->set("neili",n-500);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N����������ʯ�����ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","��ʯ������ԭλ���ֵ�ס�˶��ڡ�\n", room);
         room->delete("exits/enter");
   }
int do_jump(string arg)
{
        object me;
me = this_player();

        if (arg !="zhulin") 
return notify_fail("��Ҫ�굽����ȥ��\n");
if( arg=="zhulin")
        {
            
                    write("����������������֡�\n");
                    message("vision",
                             me->name() + "�������˹�ȥ��\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"zhulin10");
                    message("vision",
                    me->name() + "�����������˹�����\n",
                                environment(me), ({me}) );
                }
                return 1;
 }
