//tongpai1.c
//edit by noz

inherit ITEM;

void create()
{
  set_name( "����ͭ��",({"e pai"}));
  set_weight(100);

  if( clonep() )
        set_default_object(__FILE__);

  set("unit", "��");
  set("long", "����һ����������İ�ͭƬ�ӣ�Լ�а��ƴ�С�������������һ��������ɷ��������ʮ�ֹ��졣\n");
  set("value", 100);

  setup();
}

