// /u/beyond/mr/jiashan.c
// this is made by beyond
// update 1997.6,20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"��ɽ"NOR);
         set ("long",@long
����һ��ɽ����ɽ�϶�Ѩ�ܶ࣬һ��΢�紵������Ѩ�������쬡�����
����������Щë���Ȼ���Ա���һ����ʯ(shi)��
long);
         set("item_desc", ([
             "shi" : "�����ʯ�Ѿ����ɶ��ˣ���֪�ܲ���(break)����\n",
]));

setup();
}

void init()
{
    add_action("do_break", "break");
    add_action("do_jump","jump");
}
int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="shi" ) {
                write("��Ҫ����ʲô�Ķ�����\n");
                return 1;
        }

  message_vision(
   "$N����һ������˫��ͬʱ�ĳ���\n", this_player());

  if (n>=200) {
        message_vision(
 "$Nֻ��һ�����䡱��һ����$N����ʯ���ˣ�������һ�����ڡ�\n", this_player());
        set("exits/down", __DIR__"shandong");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","��ʯ������ԭλ���ֵ�ס�˶��ڡ�\n", room);
         room->delete("exits/down");
   }
int do_jump(string arg)
{
        object me;
me = this_player();

        if (arg !="shuichi") 
return notify_fail("��Ҫ����ȥ��\n");
if( arg=="shuichi")
        {
            
                    write("������Ծ��������ˮ�رߡ�\n");
                    message("vision",
                             me->name() + "һ�������˹�ȥ��\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"shuichi");
                    message("vision",
                    me->name() + "��ˮ�������˹�����\n",
                                environment(me), ({me}) );
                }
                return 1;
 }

