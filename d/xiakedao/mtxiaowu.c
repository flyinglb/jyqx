// mtxiaowu.c ľ��

inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @TEXT
������һ����С��ľ�ݣ����з���һЩ���߰���ļҾߣ�ǽ��
�߻���һ�����õ�С������һ��Ӣ��������������������ȥ���ƺ�
��ʲô���£���ʱ�ķ���������̾...... 
TEXT );
       set("exits", ([
           "west" : __DIR__"mtdating",
       ]));
       set("objects",([
           __DIR__"npc/shizhongyu" : 1,
       ]));
       setup();
       replace_program(ROOM);
}
