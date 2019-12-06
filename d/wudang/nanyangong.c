//Room: nanyangong.c ���ҹ�
//Date: Sep 29 1997

#include <ansi.h>
inherit ROOM;

void close_andao();
string look_xiang();
int do_move(string arg);

void create()
{
      set("short","���ҹ�");
      set("long",@LONG
�����Ǿ������ҹ����˹���������֮�¡�������������������������
�����������쾮�������Ծ����ٻ�������
    �м���װ����Ŀ���䵱�������Ӵ���Ҵ��߹���
    �����̨�������佣����ʦ���·Ͷʦ�����ء�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"shizhu",
          "southup": __DIR__"gaotai",
      ]));
      set("item_desc",([
          "��������" :       (: look_xiang :),
      ]));
      set("no_clean_up", 0);
      setup();
}

int valid_leave(object ob, string dir)
{
        mapping myfam;
        ob = this_player();
        myfam = (mapping)ob->query("family");
        if ((int)ob->query("combat_exp",1)<10000 && (dir == "southup"))
            return notify_fail("��������佣������̫���㱻�����ĵ���������ȥ��\n");
        if ((!myfam || (myfam["family_name"] != "�䵱��")) && (dir == "southup"))
            return notify_fail("���䵱���ӣ������������佣��\n");
        return 1;
}

void init()
{
        add_action("do_move", "move");
}

string look_xiang()
{
        return
        "��������ͭ��ͣ����Դ��𣬹������ֻ�Ǻ�����������ڵò��������롣\n";
}

int do_move(string arg)
{
        object room, ob;

        ob = this_player();
        if( !arg || arg!="xiang" ) return notify_fail("����İ��費���Ҷ���\n");
        message_vision(HIC
          "$N�ߵ��������񱳺�����ʹ�������Ͼ������������ţ������ƶ��ˡ���\n"
          "����¶��һ���󶴣�����ʯ��������ȥ�����������ͨ��һ��������\n"NOR, ob);
        set("exits/down", __DIR__"nanyan0");
//        message_vision(HIC"$N������ԥһ�ݶ��¡���\n\n\n"NOR,ob);

        if( room = find_object(__DIR__"nanyan0") )
        {
           room->set("exits/up", __FILE__);
           message("vision", "�컨���Ȼ����������������¶��һ�����ϵ�¥�ݡ�\n",room );
        }
//        ob->move(__DIR__"nanyan0");
        remove_call_out("close_andao");
        call_out("close_andao", 3);
        return 1;
}

void close_andao()
{
    object room;

    if (!query("exits/down")) return;
    message("vision","ֻ��ƹ��һ���죬�Ͼ����Զ��ƻ�ԭ����\n", this_object() );
    if( room = find_object(__DIR__"nanyan0") )
    {
//        room->delete("exits/up");
        message("vision","ֻ��ƹ��һ���죬���ϵĶ����Զ�����ʵʵ�ع���������\n",room);
    }
    delete("exits/down");
}
