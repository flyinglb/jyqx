// wallw3.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG
����Į����ֱ����������Բ����Ҳֻ�������־��򺮵أ���
�д��ֺ����澰�������ձ���ɽ���������������ž������Ĵ�
Į֮�ϣ�����������ֱ��������εΪ��ۡ���Ұ������һ�����
��Į�ĳ��ӣ�����ס�˺������ա���ɫ������ֱ�������һ��
�����ȥ���̶�һ�����ʱ���ڣ����˵���꣬ҲΪ֮�𺳡� 
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "east" : __DIR__"wallw2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup(); 
        replace_program(ROOM);
}

