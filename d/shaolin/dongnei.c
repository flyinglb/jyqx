// dongnei.c
// this is made by beyond
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@long
��������һ�����ܵĵط�������ʮ�ֵĿ������������л�
����(jiguan ren)����֪����ʲô���ã��������ǵ�ֻ�м���
���ֵ����������������Ա߻��м������ֵ����ڴ������ɡ���
�߻���һ���޴��ʯͷ����ʱ�Ķ��ڶµ����ϵġ�
long);
        set("item_desc", ([

 "jiguan ren" : "���ǰ����������ģ��������ģ�����֪����ʲô���á�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_break","break");
        add_action("do_study", "bihua");
        add_action("do_study", "duilian");
}

int do_study(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");

        if (arg != "jiguan ren") return 0;
        c_skill=(int)ob->query_skill("unarmed", 1);

        if (ob->query("jing")<100)
                return notify_fail("��̫���ˣ��Ѿ�û���������ͻ����˶������ˣ�\n");
        if (c_skill< 200)
                return notify_fail("��������˶�����һ�ᣬ�о�������˶��������򲻵�ʲô�ˡ�\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 50);
                return notify_fail("��ľ��鲻�����޷���������ʲô�ˡ�\n");
        }

        message_vision("$N������˶�����һ�ᣬ�ƺ��о��Լ��Ļ���ȭ���е㳤����\n",ob);
        ob->improve_skill("unarmed", random(100*ob->query_int()));
        ob->receive_damage("jing", 70);
        return 1;
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
 "$Nֻ��һ�����䡱��һ����$N����ʯ���ˣ�һ�����ϵĶ��ڳ���������ǰ��\n", this_player());
        set("exits/out", __DIR__"linnei");
        this_player()->set("neili",n-500);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",10);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","��ʯ������ԭλ���ֵ�ס�˶��ڡ�\n", room);
         room->delete("exits/up");
   }



