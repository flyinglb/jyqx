// damen.c ����
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
string look_gate();
int do_knock(string arg);

void create()
{
        set("short", "ȫ��̴���");
        set("long", @LONG
�����ߵ�������ɽ��ɽ����ǰ�����ȫ��̵��ܲ��������ˡ���
����ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ���ġ�
��ǰ����ǽ���ߣ��������ݣ�����һ�����������������ߵ����ɼ
ľ��ͭ����(gate)�����Ʋ��������Ϲ���һ����(bian)����ǰ��ʯ��
�Ϲ���һ������(duilian)��
LONG
        );
        set("exits", ([
//                "east" : __DIR__"datang1",
                "westdown" : __DIR__"jiaobei",
        ]));
        set("outdoors", "quanzhen");
        set("item_desc", ([
            "gate":
"һ���������ߵ�"HIR"���ɼľ"HIY"��ͭ"NOR"���š�\n",
            "bian": HIG"
��������������������������
��������������������������
������ȫ���桡�š���  ����
��������������������������
��������������������������
\n"NOR,
            "duilian": BLINK+HIW"
һ������������������\n
�ط����취��������Ȼ
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhike" : 1,
        ]));
        setup();
}

void init()
{
    add_action("do_knock", "knock");
}

void close_gate()
{
    object room;

     if(!( room == find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("qingguan", room)))
            message("vision", "֪�͵�����ǰ�Ѵ��Ź���������\n", room);
        else
            message("vision", "��ͯ��ǰ�Ѵ��Ź���������\n", room);
     }
   else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "gate" && arg != "east"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        set("exits/east", __DIR__"datang1");
        message_vision("$N������������ţ�ֻ��֨��һ����"
            "һλ��ͯӦ���򿪴��ţ�\n"
            "���þ����Ŀ���������´�����$N��\n",
            this_player());
        room->set("exits/west", __FILE__);
        message("vision", "���洫��һ������������ͯӦ����ǰ�Ѵ��ſ���\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "east" )
    {
        return ::valid_leave(me, dir);
    }
    if (!query("exits/east"))
        return 0;

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "ȫ���"))
    {
        if (me->query("class") != "taoist")
        {
            return notify_fail("��ͯ˵�����Բ����׼ҵ��Ӳ����빬���С�\n");
        }
        write("��ͯ�����ÿ���˵����ʦ�������ˣ������\n");
        return 1;
    }
    else if( present("chongyang ling", me) )
    {
        write("��ͯ������ף������ÿ���˵����ԭ���ǹ�ͼݵ�����������\n");
        return 1;
    }
    if (me->query("shen") >= 0)
         return notify_fail("��ͯ˵������λʩ����ذգ����������Ӵ����ˡ�\n");
    return notify_fail("��ͯ˵�������аħ������������򲻽��ɣ����ˣ�\n");

}

string look_gate()
{
    return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
