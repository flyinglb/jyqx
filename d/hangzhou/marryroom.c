// marry_room.c
#include <room.h>
inherit ROOM;
string look_zhaopai(object me);
void create()
{
        set("short", "����ׯ");
        set("long", @LONG
��������վ�ڷ�����������Ӻ��ϵĺ���ׯ���ˮƾ��������
���̵ĺ��棬���Ƕ����ˡ�����ׯ�����󣬵�����ȴ������֮������
�ϣ��ɾ��������������ˡ�
    �����ſڵĵط���һ����ľ��ɵ�����(zhaopai)��
LONG);
        set("exits", ([
            "east" : __DIR__"road10",
        ]) );
        set("item_desc", ([
            "zhaopai": (: look_zhaopai :),
        ]) );
        set("objects", ([
            __DIR__"npc/hongniang" : 1,
        ]) );
        set("no_fight",1);
        set("no_steal",1);
        set("no_clean_up", 0);
        setup();
}

string look_zhaopai(object me)
{
        return "�޽�(marry)����(unmarry)��Լ��\n";
}
