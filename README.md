import React from "react";
import { Card, CardContent } from "@/components/ui/card";
import { Button } from "@/components/ui/button";
import { BookOpen, Code, Image } from "lucide-react";

export default function GraphicsLab() {
  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-950 via-slate-900 to-slate-950 text-slate-100 p-8">
      <header className="mb-12 text-center">
        <h1 className="text-4xl font-bold tracking-tight">Computer Graphics Lab</h1>
        <p className="mt-3 text-slate-400">Structured lab work • Clean code • Visual output</p>
      </header>

      <section className="grid gap-8 md:grid-cols-3">
        {/* LAB 1 */}
        <Card className="bg-slate-900 border-slate-800 rounded-2xl shadow-lg hover:scale-[1.02] transition">
          <CardContent className="p-6">
            <div className="flex items-center gap-3 mb-4">
              <Code className="w-6 h-6 text-blue-400" />
              <h2 className="text-xl font-semibold">Lab 1</h2>
            </div>
            <p className="text-slate-400 text-sm mb-4">
              Basic graphics primitives and first drawing programs.
            </p>
            <Button variant="outline" className="w-full">View Source</Button>
          </CardContent>
        </Card>

        {/* LAB 2 */}
        <Card className="bg-slate-900 border-slate-800 rounded-2xl shadow-lg hover:scale-[1.02] transition">
          <CardContent className="p-6">
            <div className="flex items-center gap-3 mb-4">
              <Image className="w-6 h-6 text-green-400" />
              <h2 className="text-xl font-semibold">Lab 2</h2>
            </div>
            <p className="text-slate-400 text-sm mb-4">
              Line, circle, and shape drawing algorithms with visuals.
            </p>
            <Button variant="outline" className="w-full">View Output</Button>
          </CardContent>
        </Card>

        {/* LAB 3 */}
        <Card className="bg-slate-900 border-slate-800 rounded-2xl shadow-lg hover:scale-[1.02] transition">
          <CardContent className="p-6">
            <div className="flex items-center gap-3 mb-4">
              <BookOpen className="w-6 h-6 text-purple-400" />
              <h2 className="text-xl font-semibold">Lab 3</h2>
            </div>
            <p className="text-slate-400 text-sm mb-4">
              Transformations, scaling, rotation, and real examples.
            </p>
            <Button variant="outline" className="w-full">Read Docs</Button>
          </CardContent>
        </Card>
      </section>

      <footer className="mt-16 text-center text-slate-500 text-sm">
        © 2025 • Shishir Bhattarai • Computer Graphics Lab
      </footer>
    </div>
  );
}
