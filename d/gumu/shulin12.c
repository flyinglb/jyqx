// shulin12.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ܸС���������
����һ��С����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shulin11",
                "northdown" : __DIR__"shandao3",
        ]));
        set("objects", ([
                "/d/wudang/npc/monkey" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
