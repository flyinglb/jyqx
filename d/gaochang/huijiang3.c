// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "�Ͻ�С��");
        set("long", @LONG
�Ӳ�ԭ������, ��ӽ��Ͻ�ɳĮ�ˡ���������𽥸���, ����ʱ����ɳ
Į��ӿ����ɳĮ�ﻹ���������̶�, �������Ϣ�ͷַ����������������,
����������ʮ�����֡�������һСԺ��
LONG
        );
        set("exits", ([
            "northup" : __DIR__"huijiang2",
            "west" : __DIR__"huijiang4",
            "northeast" : __DIR__"huijiang5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
