//Room: hcawest.c �����ֲ��
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_chuang();
string look_paizi();

void create()
{
      set("short","�����ֲ��");
      set("long",@LONG
�����ǽ𶥻����������ǽӴ���ͼ������ĵط������ڰ��ż������ӣ�
����Χ���������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ������顣�м�
λ���������Ʒ����������ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ��
��Ĺ�������һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ��
�д����ˡ��ϱ����ȴ���(chuang)��
LONG);
      set("objects", ([
           CLASS_D("emei") + "/wenqing" : 1,
      ]));
      set("item_desc", ([
          "chuang" : (: look_chuang :),
          "paizi"  : (: look_paizi :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"   : __DIR__"hcazhengdian", 
      ]));
//      set("no_clean_up", 0);
      setup();
}

string look_chuang()
{
    return "������Կ�����üɽ������ɽ���������и�С����(paizi)��\n";
}
string look_paizi()
{
    return "������д�ţ���������Ϊ���أ�������(jump)����\n";
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        if (!arg ||arg !="chuang") return 1;
        me = this_player();
        message_vision("$N���˲�ע�⣬�������⡣\n",me);
        me->move(__DIR__"xiaoshulin1");
        message_vision("$N�ӻ�����������������\n",me);
        return 1;
}
