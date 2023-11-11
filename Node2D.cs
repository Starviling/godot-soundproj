using Godot;
using System;

public partial class Node2D : Godot.Node2D
{
	private static HttpRequest? httpRequest;

	public static void SomethingBoring(Action<int> randomItem)
	{
		randomItem.Invoke(1);
		
	}

	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		GD.Print("test");
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}
}
