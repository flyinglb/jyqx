// Room: /d/shaolin/cjlou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£�����
�˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ���������
��������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��
ͨ�硣�м����������Ŵ���ܡ�Ľ�ݸ����ǲ�����ˣ�͵ѧ����
��ѧ��
LONG );
        set("exits", ([
                "south" : __DIR__"cjlou",
        ]));
        set("objects",([
//                CLASS_D("shaolin") + "/hui-zhen" : 1,
                  "/d/murong/npc/murong-bo": 1,
                  "/d/murong/npc/saodiseng": 1,
//                "/clone/book/yijinjing" : 1,
        ]));
//      set("no_clean_up", 0);
        setup();
}

