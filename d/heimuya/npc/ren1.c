// renying.c

inherit NPC;
string inquiry_linghuchong();

void create()
{
	
    set_name("��ӯӯ", ({ "ren ying ying","ren","ying"}) );
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "����ķ��飬��̬���ţ��俴��ȥ���ýӽ�����������������ʧΪһ���˵����ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",60);
    	set("chat_msg",({
	    "��֪��������������,�Ƿ��ֺ���С������һ��......\n",
        "�����ܰ�������Ը�������̫лл����.............\n",
        "Ҳ��֪����˼�û�����������漱������.......\n",
	   }) );
       
	   create_family("������̵�",2,"����-->ʥ��");
       set("inquiry",([
	   "�����" : (: inquiry_linghuchong:),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/d/heimuya/npc/obj/jin")->wear();
       carry_object("/d/heimuya/npc/obj/letter");
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("ȥ���ϻ�ɽһȥ����������,�����������Ұ�......\n"
	 , me );
 if(query_temp("letter")==0)
 {  message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���
       �����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "";
 }
   message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"����������
       ��, ��Ҫ���ҵ������塻���Ͱ��Ž��������������׵ġ�\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("����ŷ��㽻������塣\n");
}
