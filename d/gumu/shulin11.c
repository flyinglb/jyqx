// shulin11.c
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
                "south"     : __DIR__"shulin10",
                "northdown" : __DIR__"shulin12",
        ]));
        setup();
        replace_program(ROOM);
}
