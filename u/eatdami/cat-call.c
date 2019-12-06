
inherit ITEM;

void create()
{
	set_name("黑哨", ({"cat-call", "shao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个精制的小铁哨,你可以「chui」\n");
		set("value", 100);
		set("material", "steel");
	}
	setup();
}

int query_autoload(){return 1;}

int init()
{
 add_action("do_chui","chui");
}
int do_chui(string arg)
{
   object pet,me=this_player();
    
  if(!(me->query("pet/make")))   
	return notify_fail("你吹了吹黑哨,什么事也没发生!\n");
  if((pet=find_living(me->query("pet/id")))&&(pet!=find_player(me->query(
            "pet/id")))){
  if(pet->query("p_host")==me->query("id"))
     {
      tell_room(environment(pet),"只听一声清脆的哨声,"+pet->query("name")+"跑开了.\n",pet);
      pet->move(environment(me));
      tell_room(environment(me),pet->query("name")+"向你跑了过来.\n",pet);
      pet->set_leader(me);
    return 1;
      }
  else{
       if(!stringp(me->query_temp("pet_in")) )
	{ pet=new("/u/wind/cat", 1);
      me->set_temp("pet",pet);
      me->set_temp("pet_in","1");

     pet->move(environment(me));
     tell_room(environment(me),"哨声一响,"+pet->query("name")+"从一边窜了出来!\n",pet);
return 1;
      }
    return notify_fail("你吹了吹口哨,什么事情也没发生!\n");
     }
   }
else{
      if(!stringp(me->query_temp("pet_in")) )
{
	pet=new("/u/wind/cat",1);
      me->set_temp("pet",pet);
      me->set_temp("pet_in","1");
      pet->move(environment(me));   
      pet->set_leader(me);
      tell_room(environment(me),"只听哨声一响,"+pet->query("name")+"从一边窜了出来.\n",pet);
  return 1;
    }
 return notify_fail("你吹了吹口哨,什么事情也没发生\n");
}
}
   
