// zhangma.c

inherit NPC;
string inquiry_hua();

void create()
{
	set_name("����", ({ "zhang ma","zhang","ma"}) );
	set("gender", "Ů��" );
	set("age", 50);
	set("long", "һ��������ɣ�������š�\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",60);
	set("chat_msg",({
	    "������߶�ţ��ҿ����ġ��𻨡�Ӵ��������������Ӵ��\n",
	    "���谵��Ĩ�˰����ᡣ\n",
	    "�������˵�����ҵġ��𻨡�ѽ��������Ʋ�����Ը������ˣ�\n"
	   }) );
       set("inquiry",([
	   "��" : (: inquiry_hua :),
	   ]) );
       set_temp("shoe",1);
       setup();
       carry_object("/clone/misc/cloth")->wear();
}

string inquiry_hua()
{
 object me=this_player();
 object obn;
 message_vision("����˵������λ"+ RANK_D->query_respect(me)+"�����𻨡����ҵ��׹�Ů��
	 �����Т˳�ˣ�\n��ϧȥ����ɽ��ݾ�һȥ���ᣬҲ��֪�����ǻ����\n"
	 , me );
 if(query_temp("shoe")==0)
 {  message_vision("������˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���
       ��ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "";
 }
   message_vision("������˵������λ"+ RANK_D->query_respect(me)+"����������
       �����ڲݴ����һֻ���廨Ь����\n
       ��Ҫ���ҵ����𻨡����Ͱ�Ь���������������׵ġ�\n
       ��Ů�����𻨡������ˣ����и����ˡ�\n" , me);
   obn=new("/d/baituo/obj/shoe");
   obn->move(me);
   set_temp("shoe",0);
   return "����ӻ�������һֻ���廨Ь���������㡣\n";
}
