import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final TextEditingController panjangController = TextEditingController();

  final TextEditingController lebarController = TextEditingController();

  double? _hasil;
  String? _kategori;
  Color? _warna;

  void _reset() {
    setState(() {
      _hasil = null;
      _kategori = null;
      _warna = null;

      panjangController.clear();
      lebarController.clear();
    });
  }

   void _kelilingHitung() {
  double? panjang = double.tryParse(panjangController.text);
  double? lebar = double.tryParse(lebarController.text);

  if (panjang == null || lebar == null) {
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(
        content: Text("Silakan masukkan panjang dan lebar terlebih dahulu!"),
      ),
    );
    return;
  }

  double hasilKeliling = 2 * (panjang + lebar);

  setState(() {
    _hasil = hasilKeliling;
    _kategori = "Keliling Persegi Panjang";
    _warna = Colors.blue;
  });
}

 void _luasHitung() {
  double? panjang = double.tryParse(panjangController.text);
  double? lebar = double.tryParse(lebarController.text);

  if (panjang == null || lebar == null) {
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(
        content: Text("Silakan masukkan panjang dan lebar terlebih dahulu!"),
      ),
    );
    return;
  }

  double hasilLuas = panjang * lebar;

  setState(() {
    _hasil = hasilLuas;
    _kategori = "Luas Persegi Panjang";
    _warna = Colors.green;
  });
}
@override
void dispose() {
  panjangController.dispose();
  lebarController.dispose();
  super.dispose();
}
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Erie Achmad Hariry'),
          backgroundColor: Colors.grey,
          foregroundColor: Colors.white,
          centerTitle: true,
        ),
        body: Padding(
          padding: const EdgeInsets.all(25.0),
          child: Column(
            children: [
              TextField(
                controller: panjangController,
                keyboardType: TextInputType.number,
                decoration: const InputDecoration(
                  labelText: "Input Panjang (CM)",
                  icon: Icon(Icons.height),
                ),
              ),

              const SizedBox(height: 25),

              TextField(
                controller: lebarController,
                keyboardType: TextInputType.number,
                decoration: const InputDecoration(
                  labelText: "Input Lebar (CM)",
                  icon: Icon(Icons.square_foot),
                ),
              ),

              const SizedBox(height: 25),

              Row(
                children: [
                  Expanded(
                    child: ElevatedButton(
                      onPressed: _kelilingHitung,
                      style: ElevatedButton.styleFrom(
                        backgroundColor: Colors.blue,
                        foregroundColor: Colors.white,
                      ),
                      child: const Text("Keliling"),
                    ),
                  ),

                  const SizedBox(width: 15),

                  Expanded(
                    child: ElevatedButton(
                      onPressed: _luasHitung,
                      style: ElevatedButton.styleFrom(
                        backgroundColor: Colors.green,
                        foregroundColor: Colors.white,
                      ),
                      child: const Text("Luas"),
                    ),
                  ),

                  const SizedBox(width: 15),

                  Expanded(
                    child: ElevatedButton(
                      onPressed: _reset,
                      style: ElevatedButton.styleFrom(
                        backgroundColor: Colors.red,
                        foregroundColor: Colors.white,
                      ),
                      child: const Text("Reset"),
                    ),
                  ),
                ],
              ),

              const SizedBox(height: 30),

              Text(
                _hasil != null ? _hasil!.toStringAsFixed(1) : "0.0",
                style: TextStyle(
                  fontSize: 30,
                  color: _warna,
                  fontWeight: FontWeight.bold,
                ),
              ),

              const SizedBox(height: 10),

              Text(
                _kategori ?? "Hitung Keliling atau Luas",
                style: TextStyle(fontSize: 22, color: _warna),
                textAlign: TextAlign.center,
              ),
            ],
          ),
        ),
      ),
    );
  }
}
