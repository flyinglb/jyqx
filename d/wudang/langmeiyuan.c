//Room: landmeiyuan.c ��÷԰
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","��÷԰");
      set("long",@LONG
������������÷������ɫ��ǳһ���һ����ٴ�˿������״���ƺ�÷����ɽ
�е����������ഫ��һ������۰�÷֦�����Ƹ��ϣ��ö����ϣ��ɴ����֡���
˵��÷���˲����Դ����䵱ɽ��Υ�߱��ⲻ����
LONG);
// Ӧ�ɲ�ժ��÷����Բ�������ʵ���ֹ��
      set("objects", ([
            CLASS_D("wudang") +"/shouyuan": 1,

      ]));
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"taiziyan",
          "southup"  : __DIR__"wuyaling",
          "westup"   : __DIR__"nanyanfeng",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
