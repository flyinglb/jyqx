inherit ROOM;

void create()
{
        set("short", "�ȱ�Ժ");
        set("long",@LONG
����ɮ���ǵ㻯��ͽ�ĵط������ٽ���������������˴��ɱɱ
�����ӣ������˴��䷢Ϊɮ���������š�ǽ��һ�������������߸�
��һ���������飺�������������سɷ�
LONG );
        set("exits", ([
                "east" : __DIR__"wuwujing",
		"south" : __DIR__"sanwugong",
	]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
