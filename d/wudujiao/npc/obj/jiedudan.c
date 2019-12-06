// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

string *names = ({
  "��ɫ�ⶾ��",
  "��ɫ�ⶾ��",
  "��ɫ�ⶾ��",
  "��ɫ�ⶾ��",
  "��ɫ�ⶾ��",
});
string *name = ({
  "red dan",
  "yellow dan",
  "green dan",
  "white dan",
  "black dan",
});

void create()
{
  set_name("��ʽ�ⶾ��", ({"jiedu dan", "dan", "yao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��������С�ĵ��衣\n");
    set("unit", "��");
    set("value", 20000);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
  set("no_sell",1);
}

void init()
{
  int num = random(sizeof(names));
  if (query("name")=="��ʽ�ⶾ��")
    set_name(names[num], ({name[num]}));
// ::init();
        add_action("do_eat", "eat");

}
int do_eat(string arg)
{
  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
  if(arg=="red dan"||arg=="yellow dan"||arg=="green dan"
     ||arg=="white dan"||arg=="black dan") 
  {
      object ob;
      ob=this_object();
      if((string)ob->query("name")=="��ɫ�ⶾ��"&& arg=="red dan"){
         if((int)this_player()->query_condition("snake_poison") <1)
         tell_object(this_player(), HIG "�����һ�ú�ɫ�ⶾ�������ƺ�û��ʲôЧ����\n" NOR );
         else {
         tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
         this_player()->apply_condition("snake_poison", 0);
          }
         destruct(this_object());
         return 1;
        }
      if((string)ob->query("name")=="��ɫ�ⶾ��"&& arg=="yellow dan"){
         if((int)this_player()->query_condition("wugong_poison") <1)
         tell_object(this_player(), HIG "�����һ�û�ɫ�ⶾ�������ƺ�û��ʲôЧ����\n" NOR );
         else {
         tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
         this_player()->apply_condition("wugong_poison", 0);
         }
         destruct(this_object());
         return 1;
       }
      if((string)ob->query("name")=="��ɫ�ⶾ��"&& arg=="green dan"){
         if((int)this_player()->query_condition("zhizhu_poison") <1)
         tell_object(this_player(), HIG "�����һ����ɫ�ⶾ�������ƺ�û��ʲôЧ����\n" NOR );
         else {
         tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
         this_player()->apply_condition("zhizhu_poison", 0);
         }
         destruct(this_object());
         return 1;
       }
      if((string)ob->query("name")=="��ɫ�ⶾ��"&& arg=="white dan"){
         if((int)this_player()->query_condition("xiezi_poison") <1)
         tell_object(this_player(), HIG "�����һ�ð�ɫ�ⶾ�������ƺ�û��ʲôЧ����\n" NOR );
         else {
         tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
         this_player()->apply_condition("xiezi_poison", 0);
         }
         destruct(this_object());
         return 1;
       }
      if((string)ob->query("name")=="��ɫ�ⶾ��"&& arg=="black dan"){
         if((int)this_player()->query_condition("chanchu_poison") <1)
         tell_object(this_player(), HIG "�����һ�ú�ɫ�ⶾ�������ƺ�û��ʲôЧ����\n" NOR );
         else {
         tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
         this_player()->apply_condition("chanchu_poison", 0);
         }
         destruct(this_object());
         return 1;
       }
  }
return 1;
}
