// stamps.c
inherit ITEM;
void create()
{
	set_name("��Ʊ", ({"pawn stamp", "stamp"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
    else  {
	   set("unit", "��");
	   set("long", "һ��ո�µĿհ׵�Ʊ����֪���ܲ����á�\n");
	   set("value", 0);
	   set("no_sell", 1);
}
}
string long()
{
   string msg;
   if(!query_temp("long_1") || !query_temp("long_2"))
	  return query("long");
   msg = "���յ�\n";
   msg += "   "+query_temp("long_1")+"\n";
   msg += "   "+query_temp("long_2")+"\n";
   return msg;
}
void remove(string euid)
{
   object ob=query_temp("file");
   object env;
   if(ob && (!objectp(env=environment(ob)) ||
      env->query("id")=="treasure box")) destruct(ob);
   ::remove();
}
